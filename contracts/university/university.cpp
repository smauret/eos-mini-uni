#include "university.h"

void university::addstudent(name username) {
    // Ensure this action is authorized by the student todo professor
    require_auth(username);

    // Create a record in the table if the student doesn't exist in our app yet
    auto student_iterator = _students.find(username.value);
    if (student_iterator == _students.end()) {
        student_iterator = _students.emplace(username,  [&](auto& new_student) {
            new_student.username = username;
            new_student.grade = 4;
        });
    }
}