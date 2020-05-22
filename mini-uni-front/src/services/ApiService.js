import { Api, JsonRpc } from 'eosjs';
import { JsSignatureProvider } from 'eosjs/dist/eosjs-jssig'

// Main action call to blockchain
async function takeAction(action, dataValue) {
    const privateKey = '5KGpcDeuZzik9mPriBMhEZJPW9cpNjTTVQgdL2hVnpQKFd3u4tn';
    const rpc = new JsonRpc(process.env.REACT_APP_EOS_HTTP_ENDPOINT);
    const signatureProvider = new JsSignatureProvider([privateKey]);
    const api = new Api({ rpc, signatureProvider, textDecoder: new TextDecoder(), textEncoder: new TextEncoder() });

    // Main call to blockchain after setting action, account_name and data
    try {
        const resultWithConfig = await api.transact({
            actions: [{
                account: process.env.REACT_APP_EOS_CONTRACT_NAME,
                name: action,
                authorization: [{
                    actor: 'university',
                    permission: 'active',
                }],
                data: dataValue,
            }]
        }, {
            blocksBehind: 3,
            expireSeconds: 30,
        });
        return resultWithConfig;
    } catch (err) {
        throw(err)
    }
}
class ApiService {
    static async getTable(table) {
        try {
            const rpc = new JsonRpc(process.env.REACT_APP_EOS_HTTP_ENDPOINT);
            const result = await rpc.get_table_rows({
                "json": true,
                "code": process.env.REACT_APP_EOS_CONTRACT_NAME,    // contract who owns the table
                "scope": process.env.REACT_APP_EOS_CONTRACT_NAME,   // scope of the table
                "table": table,    // name of the table as specified by the contract abi
            });
            return result;
        } catch (err) {
            console.error(err);
        }
    }

    static async addStudent (dataValue){
        try{
            takeAction("addstudent", dataValue)
        }catch (err){
            console.log(err)
        }
    }

}

export default ApiService;