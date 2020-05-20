import React, {useEffect, useState} from 'react';
import { ApiService } from 'services';

function App() {
  const [studentsTable, setStudentsTable] = useState({})
  const [error, setError] = useState('no error')

  useEffect( ()=>{
        ApiService.getStudentsTable()
        .then((res) => {
          setStudentsTable(res);
        })
        .catch(err => {
          setError(err.toString());
        });
  })

  return (
    <div>
      students: {JSON.stringify(studentsTable)}
      error: {error}

    </div>
  );
}

export default App;
