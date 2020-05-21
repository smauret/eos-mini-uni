## Getting started

* Follow this [link](https://developers.eos.io/welcome/latest/getting-started/development-environment/introduction) for setup until section 2.1 "Hello World Contract"

* Clone this repo

* In the ``mini-uni-front`` folder
     ```
      npm install
      npm start
     ```
* Open terminal and start keos
    ```
      keosd &
    ```

* Start nodeos
    ```
      nodeos -e -p eosio \
      --plugin eosio::producer_plugin \
      --plugin eosio::producer_api_plugin \
      --plugin eosio::chain_api_plugin \
      --plugin eosio::http_plugin \
      --plugin eosio::history_plugin \
      --plugin eosio::history_api_plugin \
      --filter-on="*" \
      --access-control-allow-origin='*' \
      --contracts-console \
      --http-validate-host=false \
      --verbose-http-errors >> nodeos.log 2>&1 &
    ```
  
## Contract deployment

* Go to `contracts\university\` in terminal and in compile with
    ```
    eosio-cpp -o university.wasm university.cpp
   ```

* Create an account for the contract (make your wallet is unlock - `cleos wallet unlock`)    
    ```
    cleos create account eosio university public_key
    ```

* Finally deploy the contract
    ```
    cleos set contract university /home/name/Documents/dev/eos-mini-uni/contracts/university --abi university.abi -p university@active
    ```  
  
## Test

* Add a student to the table

    ```
    cleos push action university addstudent '["university"]' -p university@active
    ```
  
* Go to your browser and check that the table is displayed
