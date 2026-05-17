require("dotenv").config();

const userModel = require("../models/userModel");
const jwt = require("jsonwebtoken");
const bcrypt = require("bcrypt");

const registerUser = async (req, res) => {
    try {

        const { name, email, password } = req.body;

        if (!name || !email || !password) {
            return res.status(400).json({
                message: "Enter all fields!"
            });
        }

        const exist = await userModel.getUserByEmail(email);

        if(exist){
            return res.status(400).json({
                message: "User already exist!"
            });
        }

        const hashPass = await bcrypt.hash(password, 10);

        const user = await userModel.createUser(name, email, hashPass);

        const token = jwt.sign({ userEmail: email }, process.env.JWT_SECRET_KEY, { expiresIn: "1d" });

        res.cookie("token", token, {
            httpOnly: true,
        });

        return res.status(201).json({
            User_Name: name,
            User_Email: email
        });

    } catch (err) {
        return res.status(500).json({
            error: err
        })
    }
};

const loginUser = async (req, res) => {
    try {
        const { email, password } = req.body;

        if (!password || !email) {
            return res.status(400).json({
                message: "Enter all fields!"
            });
        }

        const user = await userModel.getUserByEmail(email);

        if (!user) {
            return res.status(404).json({
                message: "User not found!"
            });
        }

        const isValid = await bcrypt.compare(password, user.password);

        if (!isValid) {
            return res.status(401).json({
                message: "Invalid Password!"
            });
        }

        const token = jwt.sign({ userEmail: email }, process.env.JWT_SECRET_KEY, { expiresIn: "1d" });

        res.cookie("token", token, {
            httpOnly: true,
        });

        return res.status(200).json({
            User_Name: user.name,
            User_Email: email
        });


    } catch (err) {
        return res.status(500).json({
            error: err
        })
    }
};


const logoutUser = async (req, res) => {
    try {
        res.clearCookie("token", {
            httpOnly : true
        });

        return res.status(200).json({
            message: "Logout Sucessfully!"
        });
    } catch (err) {
        return res.status(500).json({
            error: err.message
        });
    }
};

const addUser = async (req, res) => {
    try {
        const { name, email, address } = req.body;

        if (!name || !email || !address) {
            return res.status(400).json({
                message: "Enter all fields!"
            });
        }

        const exist = await userModel.getNormalUserByEmail(email);

        if(exist){
            return res.status(400).json({
                message: "User already exist!"
            });
        }

        const user = await userModel.addUser(name, email, address);

        res.status(201).json({
            message: "User Added Sucessfully!"
        });

    } catch (err) {
        return res.status(500).json({
            error: err.message
        })
    }
};

const getUserById = async (req, res) => {
    try {
        const {id} = req.params;
        if (!id) {
            return res.status(400).json({
                message: "Provide ID in parameters!"
            });
        }

        const user = await userModel.readUserById(id);

        res.status(200).json({
            message: "User retrieved sucessfully!",
            name: user.name,
            email: user.email,
            address: user.address
        });

    } catch (err) {
        return res.status(500).json({
            error: err.message
        })
    }
};

const updateUserName = async (req, res) => {
    try {
        const { id } = req.params;

        const { name } = req.body;

        if (!id) {
            return res.status(400).json({
                message: "Provide ID in parameters!"
            });
        }

        if (!name) {
            return res.status(400).json({
                message: "Provide name to be updated!"
            });
        }

        const user = await userModel.updateUserNameById(id, name);

        res.status(200).json({
            message: "User updated sucessfully!",
            name: user.name,
            email: user.email,
            address: user.address
        });

    } catch (err) {
        return res.status(500).json({
            error: err.message
        })
    }
};

const deleteUser = async (req, res) => {
    try {
        const { id } = req.params;

        if (!id) {
            return res.status(400).json({
                message: "Provide ID in parameters!"
            });
        }

        const user = await userModel.deleteUserById(id);

        res.status(200).json({
            message: "User deleted sucessfully!",
            name: user.name,
            email: user.email,
            address: user.address
        })
    } catch (err) {
        return res.status(500).json({
            error: err.message
        })
    }


};

module.exports = {
    registerUser,
    loginUser,
    logoutUser,
    addUser,
    getUserById,
    updateUserName,
    deleteUser
}