const userController = require("../controllers/userController");
const express = require("express");
const router = express.Router();
const authMiddleware = require("../middlewares/authMiddleware")

router.post("/register-user", userController.registerUser);
router.post("/login-user", userController.loginUser);
router.post("/logout-user", authMiddleware, userController.logoutUser);
router.post("/add-user", authMiddleware, userController.addUser);
router.get("/get-user/:id", authMiddleware, userController.getUserById);
router.put("/update-user/:id", authMiddleware, userController.updateUserName);
router.delete("/delete-user/:id", authMiddleware, userController.deleteUser);

module.exports = router;

