require("dotenv").config();
const jwt = require("jsonwebtoken");

const authMiddleware = async(req, res, next) => {
    try{
        const token = req.cookies.token;

        if(!token){
            return res.status(401).json({
                message: "Access denied. No token provided!"
            });
        }

        const decoded = jwt.verify(token, process.env.JWT_SECRET_KEY);

        req.user = decoded; 
        
        return next();

    }catch(err){
        return res.status(403).json({
            message: "Invalid or expired token!",
            error: err.message
        });
    }
}

module.exports = authMiddleware;