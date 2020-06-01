## Contracts deployment

* Go to `contracts\university\` in terminal and compile with
    ```
    eosio-cpp -o university.wasm university.cpp
   ```
  
* Go to `contracts\job\` in terminal and compile with
    ```
    eosio-cpp -o job.wasm job.cpp
   ```

* Create an account for the contract university on [jungle testnet](https://monitor.jungletestnet.io/) (we called it samjungled12)

* Create an account for the contract job on [jungle testnet](https://monitor.jungletestnet.io/) (we called it igloojungled)

* Make sure you import your private key in wallets and that the wallets are unlock before deployment

* Finally deploy the contracts
   ```
   cleos -u http://jungle2.cryptolions.io:80 set contract samjungled12 /contracts/university --abi university.abi -p samjungled12@owner
   ``` 
  ```
  cleos -u http://jungle2.cryptolions.io:80 set contract igloojungled /contracts/job --abi job.abi -p igloojungled@owner
  ``` 
  
  
## Test

Use the front-end of this [repo](https://github.com/davthedev/mroo-front) filling the .env with your credentials.

