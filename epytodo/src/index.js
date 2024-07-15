const express = require ("express");
const app = express();
const mysql = require("mysql2");
const dotenv = require("dotenv").config();
const db = require('./config/db.js');
const port = process.env.PORT;
const path = require('path');


const bodyParser = require("body-parser");
app.use(bodyParser.urlencoded({ extended: true }));
app.use(bodyParser.json());

const views = path.join(__dirname, '../views');
    app.use(express.static(views))

const register = (require('./routes/auth/auth.js'))
    app.use(register);

const user = (require('./routes/user/user.js'))
    app.use(user)

const todo = (require('./routes/todos/todos.js'))
    app.use(todo)

app.use((req, res, next) => {
    res.status(404).sendFile(path.join(views, 'images', '../errors.png'));
});

app.listen (port, () => {
    console.log (`Example app listening at http://localhost:${port}`);
});
