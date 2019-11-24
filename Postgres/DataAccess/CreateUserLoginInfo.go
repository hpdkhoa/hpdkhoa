package main

import (
	"database/sql"
	"fmt"
	_ "github.com/lib/pq"
	"strconv"
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
	psqlInfo := fmt.Sprintf("host=%s port=%d user=%s "+
		"password=%s dbname=%s sslmode=disable",
		host, port, user, password, dbname)
	db, err := sql.Open("postgres", psqlInfo)
	if err != nil {
		panic(err)
	}
	defer db.Close()

	start := time.Now()
	for i := 1; i <= 10; i++ {
		maxid := 0
		sqlStatement := `SELECT last_value FROM userlogin_id_seq;`
		row := db.QueryRow(sqlStatement)
		switch err := row.Scan(&maxid); err {
		case sql.ErrNoRows:
			fmt.Println("No rows were returned!")
		case nil:
			//fmt.Println(maxid)
		default:
			panic(err)
		}
		//fmt.Println("Test" + strconv.Itoa(maxid + 1 + i))
		sqlStatement = `INSERT INTO userlogin (username, password)
							VALUES ($1, $2)`
		_, err = db.Exec(sqlStatement, "Test" + strconv.Itoa(maxid + 1), "202cb962ac59075b964b07152d234b70")
		if err != nil {
			panic(err)
		}
	}
	elapsed := time.Since(start)
	fmt.Println("Execute time: %s",elapsed)
}
//4.303814682s
//43.43147847s
//1.454968735s