const express = require ("express");
const app = express();
const todo = express.Router();
const bodyParser = require('body-parser');
const db = require("../../config/db.js");

todo.get('/todos', (req, res) => {
 
    const sql = "SELECT * FROM todo";

    db.query(sql, (err, results) => {
        if (err) {
            return res.status(500).json({ "msg": "Internal server error" });
        }
        res.json(results);
    });
});

todo.get("/todos/:id", (req, res) => {

    const id = req.params.id;
    const sql = "SELECT * FROM todo WHERE id = ?";

    db.query(sql, [id], (error, results) => {
        if (error) {
            return res.status(500).json({ "msg": "Internal server error" });
        }
        if (results.length > 0) {
            res.json(results);
        } else {
            res.status(404).json({"msg": "Not found"});   
        }
    });
});

todo.post("/todos", (req, res) => {
    res.send(" Hello World !");
});

todo.put('/todos/:id', (req, res) => {
    const id = req.params.id;
    res.send(" Hello World !");
});

todo.delete('/todos/:id', (req, res) => {
    const id = req.params.id;
    res.send(" Hello World !");
});

module.exports = todo;
