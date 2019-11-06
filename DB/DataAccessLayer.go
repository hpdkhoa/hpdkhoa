package DB

import (
	"database/sql"
	"fmt"
)

type UserInfo struct {
	Id int32
	username string
	password string
}

func Query_All (sourceDB, username, password, dbname string) bool {
	db, err := sql.Open(sourceDB, username + ":" + password + " @/" + dbname)
	if err != nil {
		defer db.Close()
		panic(err)
		return false
	}
	rows, err := db.Query("SELECT * FROM USERINFO")
	defer rows.Close()
	for rows.Next() {
		userInfo := UserInfo{}
		err = rows.Scan(&userInfo.Id, &userInfo.username, &userInfo.password)
		if err != nil {
			panic(err)
		}
		fmt.Println(userInfo)
	}
	err = rows.Err()
	if err != nil {
		defer db.Close()
		panic(err)
		return false
	}
	return true
}

func main() {
	Query_All("sql", "hpdkhoa", "123", "UserLoginInfo")
}