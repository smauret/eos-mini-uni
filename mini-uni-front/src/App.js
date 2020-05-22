import React, {useEffect, useState} from 'react';
import { ApiService } from 'services';

function App() {
    const [studentsTable, setStudentsTable] = useState({})
    const [professorsTable, setProfessorsTable] = useState({})

  useEffect( ()=>{
        ApiService.getTable("students")
        .then((res) => {
          setStudentsTable(res);
        })
        .catch(err => {
            console.log('err: ',err)
        });
  }, [])
    useEffect( ()=>{
        ApiService.getTable("professors")
            .then((res) => {
                setProfessorsTable(res);
            })
            .catch(err => {
                console.log('err: ',err)
            });
    },[])

    const upsertStudent = () => {
        ApiService.upsertStudent({"user":"fdqkbeofnies", "grade":1})
    }

    const upsertProf = () => {
        ApiService.upsertProf({"user":"lsqkeotnnpyu", "subject":"web"})
    }

  return (
    <div>
        <div>students: {JSON.stringify(studentsTable)}</div>
        <div>professors: {JSON.stringify(professorsTable)}</div>

        <button onClick={upsertStudent}> upsert a student</button>
        <button onClick={upsertProf}> upsert a professor</button>

    </div>
  );
}

export default App;
