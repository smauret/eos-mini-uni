#include <eosio/eosio.hpp>

using namespace std;
using namespace eosio;

class [[eosio::contract]] university : public eosio::contract {
private:
    struct [[eosio::table]] professor_info {
        name username;
        name subject;

        auto primary_key() const { return username.value; }
    };

    struct [[eosio::table]] student_info {
        name username;
        uint16_t grade;
        auto primary_key() const { return username.value; }
    };

    typedef eosio::multi_index<name("professors"), professor_info> professors_table;
    typedef eosio::multi_index<name("students"), student_info> students_table;

public:
    university( name receiver, name code, datastream<const char*> ds ):contract(receiver, code, ds){}

    [[eosio::action]]
    void upsertsdt(name user, uint16_t grade);

    [[eosio::action]]
    void removesdt(name user);

    [[eosio::action]]
    void upsertpf(name user, name subject);

    [[eosio::action]]
    void removepf(name user);
};
