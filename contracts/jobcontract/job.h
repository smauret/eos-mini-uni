#include <eosio/eosio.hpp>
#include <eosio/singleton.hpp>

using namespace std;
using namespace eosio;

class [[eosio::contract]] job : public eosio::contract {
private:
    struct [[eosio::table]] constract_info {
        string jobtitle;
        name company;
        uint64_t salary;
        string startdate;
        string address;
        uint64_t trialperiod;
        name employee;
    }tt;

    using singleton_type = eosio::singleton<"singletonjob"_n, constract_info>;
    singleton_type singleton_instance;

public:
    job( name receiver, name code, datastream<const char*> ds ):contract(receiver, code, ds), singleton_instance(receiver, receiver.value){}

    [[eosio::action]] constract_info get();

    [[eosio::action]]
    void setdetails(string jobtitle,name company, uint64_t salary, string startdate, string address, uint64_t trialperiod);

    [[eosio::action]]
    void setemployee(name user);
};
