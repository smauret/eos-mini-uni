#include "job.h"

void job::setdetails(string jobtitle,name company, uint64_t salary, string startdate, string address, uint64_t trialperiod){
    require_auth(get_self());
    if (!singleton_instance.exists())
    {
        singleton_instance.get_or_create(get_self(), tt);
    }
    auto entry_stored = singleton_instance.get();
    entry_stored.jobtitle = jobtitle;
    entry_stored.company = company;
    entry_stored.salary = salary;
    entry_stored.startdate = startdate;
    entry_stored.address = address;
    entry_stored.trialperiod = trialperiod;
    entry_stored.employee = name("");
    singleton_instance.set(entry_stored, get_self());
}

void job::setemployee(name user){
    require_auth( name("lsqkeotnnpyu"));
    if (!singleton_instance.exists())
    {
        eosio::print("Singleton is empty\n");
    }else{
        auto entry_stored = singleton_instance.get();
        entry_stored.employee = user;
        singleton_instance.set(entry_stored, get_self());
    }
}
