import React, {useEffect, useState} from 'react';
import { ApiService } from 'services';

function App() {
    const [studentsTable, setStudentsTable] = useState({})
    const [professorsTable, setProfessorsTable] = useState({})
    const [jobDetails, setJobDetails] = useState({})

  useEffect( ()=>{
        ApiService.getTableStudents()
        .then((res) => {
          setStudentsTable(res);
        })
        .catch(err => {
            console.log('err: ',err)
        });
  }, [])
    useEffect( ()=>{
        ApiService.getTableProfessors()
            .then((res) => {
                setProfessorsTable(res);
            })
            .catch(err => {
                console.log('err: ',err)
            });
    },[])

    const upsertStudent = () => {
        ApiService.upsertStudent({"user":"tomjungled14", "grade":1})
    }

    const upsertProf = () => {
        ApiService.upsertProf({"user":"samjungled13", "subject":"web"})
    }

    const addJob = () => {
        ApiService.setJobDetails({ "jobtitle":"Junior Developer","company": "igloo",  "salary":70000,  "startdate": "06/01/2020",  "address": "20 RUE GEORGES BIZET PARIS",  "trialperiod":3 })
    }

    const getJobDetails = () => {
        ApiService.getJobDetails().then((res) => {
            setJobDetails(res);
        })
            .catch(err => {
                console.log('err: ',err)
            });
    }

    const closeUniversity = () => {
        ApiService.closeUniversity()
    }


  return (
    <div>
        <div style={{margin:20}}>students: {JSON.stringify(studentsTable)}</div>
        <div style={{margin:20}}>professors: {JSON.stringify(professorsTable)}</div>
        <div style={{margin:20}}>job: {JSON.stringify(jobDetails)}</div>

        <button onClick={upsertStudent}> upsert a student</button>
        <button onClick={upsertProf}> upsert a professor</button>
        <button onClick={addJob}> add job</button>
        <button onClick={getJobDetails}> see job</button>
        <button onClick={closeUniversity}>  close university</button>

    </div>
  );
}

export default App;
