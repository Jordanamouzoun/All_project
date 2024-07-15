const express = require ("express");
const app = express();
const mysql = require("mysql2");
const hash = require('bcryptjs');
const body = require('body-parser');
const router = express.Router();
const db = require('../../config/db.js');

router.get("/",( req , res ) => {
    res.render("../views/index.html")
});

router.get('/register',( req , res ) => {
    res.render("../views/register.html")
});

router.get('/login',( req , res ) => {
    res.render("../views/login.html")
});

router.post('/register', async (req, res) => {

    const { email, name, firstname, password } = req.body;

    if (!email || !name || !firstname || !password) {
        return res.status(400).json({ "msg": "Internal server error" });
    }

    db.query('SELECT email FROM user WHERE email = ?', [email], async (error, results) => {
        try {
            if (results.length > 0) {
                return res.status(401).json({ "msg": "Account already exists" });
            }
        } catch (error) {
            res.status(500).json({ "msg": "Internal server error" });
        }
    });

    let hashpwd = await hash.hash(password, 8);
    //console.log(hashpwd);

    db.query('INSERT INTO user SET ?', { email: email, name: name, firstname: firstname, password: hashpwd }, (error, results) => {
        if (error) {
            res.status(401).json(error);
        }
        res.status(201).json({ "token": "Token of the newly registered user" });
    });
});

router.post('/login', async (req, res) => {

    const { email, password } = req.body;

    if (!email || !password) {
        return res.status(400).json({ "msg": "Internal server error" });
    }

    db.query('SELECT * FROM user WHERE email = ?', [email], async (error, results) => {

        if (error) {
            res.status(500).json({ "msg": "Internal server error" });
        }
        if (user.length === 0) {
            return res.status(401).json({ "msg": "Internal server error" });
        }
    });

    try {
        let hashpwd = await hash.hash(password, 8);
        const passwordMatch = await hash.compare(hashpwd, results[0].password);
        if (!passwordMatch) {
            return res.status(401).json({ "msg": "Invalid Credentials" });
        }
        res.status(200).json({ "token": "Token of the newly logged in user" });
    } catch (error) {
        res.status(500).json({ "msg": "Internal server error" });
    }
});

module.exports = router