const mysql = require("mysql2");
const dotenv = require("dotenv").config();
const host = process.env.MYSQL_HOST
const user = process.env.MYSQL_USER
const pwd = process.env.MYSQL_ROOT_PASSWORD
const database = process.env.MYSQL_DATABASE
const port = process.env.PORT

const db = mysql.createConnection({
    host: host,
    user: user,
    password: pwd,
    database: database
});

db.connect((error) => {
    if (error)
        console.error(error);
    if (!error)
        console.log('Connected');
});

module.exports = db;