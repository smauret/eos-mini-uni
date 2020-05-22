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

    professors_table _professors;
    students_table _students;

public:
    university( name receiver, name code, datastream<const char*> ds ):contract(receiver, code, ds),
                                                                       _professors(receiver, receiver.value),
                                                                       _students(receiver, receiver.value){}

    [[eosio::action]]
    void addstudent(name username);

    [[eosio::action]]
    void removesdt(name username);
};