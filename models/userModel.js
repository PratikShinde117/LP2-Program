const db = require("../db");

const createUser = async(name, email, password) => {
    const result = await db.query("insert into userinfo(name, email, password) values($1, $2, $3) RETURNING *", [name, email, password]);

    return result.rows[0];
}

const addUser = async(name, email, address) => {
    const result = await db.query("insert into users(name, email, address) values($1, $2, $3) RETURNING *", [name, email, address]);

    return result.rows[0];
}

const readUserById = async(id) => {
    const result = await db.query("select * from users where id = $1", [id]);

    return result.rows[0];
}

const getUserByEmail = async(email) => {
    const result = await db.query("select * from userinfo where email = $1", [email]);

    return result.rows[0];
}

const getNormalUserByEmail = async(email) => {
    const result = await db.query("select * from users where email = $1", [email]);

    return result.rows[0];
}

const updateUserNameById = async(id, name) => {
    const result = await db.query("update users set name = $1 where id = $2 RETURNING *", [name, id]);

    return result.rows[0];
}

const deleteUserById = async(id) => {
    const result = await db.query("delete from users where id = $1 RETURNING *", [id]);

    return result.rows[0];
}

module.exports = {
    createUser,
    readUserById,
    updateUserNameById,
    deleteUserById,
    getUserByEmail,
    addUser,
    getNormalUserByEmail
};