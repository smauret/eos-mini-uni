#include "university.h"

void university::upsertsdt(name user, uint16_t grade) {
    require_auth(get_self());

    students_table students( get_self(), get_first_receiver().value );
    auto iterator = students.find(user.value);
    if( iterator == students.end() )
    {
        students.emplace(get_self(), [&]( auto& row ) {
            row.username = user;
            row.grade = grade;
        });
        university::setemployee(user);
    }
    else {
        students.modify(iterator, get_self(), [&]( auto& row ) {
            row.username = user;
            row.grade = grade;
        });
        university::setemployee(user);
    }
}


void university::removesdt(name user) {
    require_auth(get_self());

    students_table students( get_self(), get_first_receiver().value );
    auto iterator = students.find(user.value);
    check(iterator != students.end(), "Record does not exist");
    students.erase(iterator);
}

void university::upsertpf(name user, name subject) {
    require_auth(get_self());

    professors_table professors( get_self(), get_first_receiver().value );
    auto iterator = professors.find(user.value);
    if( iterator == professors.end() )
    {
        professors.emplace(get_self(), [&]( auto& row ) {
            row.username = user;
            row.subject = subject;
        });
    }
    else {
        professors.modify(iterator, get_self(), [&]( auto& row ) {
            row.username = user;
            row.subject = subject;
        });
    }
}

void university::removepf(name user) {
    require_auth(get_self());

    professors_table professors( get_self(), get_first_receiver().value );
    auto iterator = professors.find(user.value);
    check(iterator != professors.end(), "Record does not exist");
    professors.erase(iterator);
}