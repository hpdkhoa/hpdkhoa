package main

import (
	"database/sql"
	"fmt"
	_ "github.com/lib/pq"
	"time"
)

const (
	//host     = "localhost"
	host     = "/var/run/postgresql"
	port     = 5432
	user     = "hpdkhoa"
	password = "123456aB"
	dbname   = "hpdkhoa"
)

func main() {
	//DB Connection
	psqlInfo := fmt.Sprintf("host=%s port=%d user=%s "+
		"password=%s dbname=%s sslmode=disable",
		host, port, user, password, dbname)
	db, err := sql.Open("postgres", psqlInfo)
	if err != nil {
		panic(err)
	}
	defer db.Close()

	start := time.Now()
	//Start time-count

	times := 1000 //No. records
	sqlStatement := `CALL INS_LOGIN_USER_DUMP($1)`
	_, err = db.Exec(sqlStatement, times)
	if err != nil {
		panic(err)
	}

	//End time-count
	elapsed := time.Since(start)
	fmt.Println("Execute time: ",elapsed)
}
//9.493564034s
//10m24.580343349s
//11.363573099s