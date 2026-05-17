const express = require("express");

const cookieParser = require("cookie-parser");

const modelroutes = require("../backend/routes/modelRoutes")

const app = express();
app.use(express.json());
app.use(cookieParser());
app.use("/api", modelroutes);

app.listen(3000, () => {
    console.log("Listening at port 3000")
})
