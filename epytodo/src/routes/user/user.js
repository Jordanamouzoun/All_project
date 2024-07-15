const express = require ("express");
const app = express();
const user = express.Router();
const hash = require('bcryptjs');
const bodyParser = require('body-parser');
const db = require("../../config/db.js");


user.get("/user", async(req, res) => {

    const sql = "SELECT * FROM user";

    db.query(sql, (error, results) => {

        if (error) {
            return res.status(500).json({ "msg": "Internal server error" });
        }
        res.json(results);
    });
});

user.get('/user/todos', (req, res) => {

    const sql = "SELECT * FROM todo";

    db.query(sql, (err, results) => {
        if (err) {
            return res.status(500).json({ "msg": "Internal server error" });
        }
        res.json(results);
    });
});

user.get("/users/:identifier", (req, res) => {

    const identifier = req.params.identifier;
    const sql = "SELECT * FROM user WHERE id = ? OR email = ?";

    db.query(sql, [identifier, identifier], (error, results) => {

        if (error)
            return res.status(500).json({ "msg": "Internal server error" });

        if (results.length > 0) {
            const user = results[0];
            hash.hash(user.password, 10, (err, hash) => {
                if (err) {
                    return res.status(500).json({ "msg": "Internal server error" });
                } else {
                    user.password = hash;
                    res.json(user);
                }
            });
        } else {
            res.status(404).json({"msg": "Not found"});   
        }
    });
});

user.put('/users/:id', (req, res) => {
    const id = req.params.id;
    res.send(" Hello World !");
});

user.delete('/users/:id', (req, res) => {
    const id = req.params.id;
    res.send(" Hello World !");
});

module.exports = user;