const express = require("express");
const router = express.Router();
const bcrypt = require("bcryptjs");
const login = require("../models/login_model");

router.post("/", function (request, response) {
  if (request.body.kortinnumero && request.body.pinkoodi) {
    const kortinnumero = request.body.kortinnumero;
    const pinkoodi = request.body.pinkoodi;
    login.checkPassword(kortinnumero, function (dbError, dbResult) {
      if (dbError) {
        response.json(dbError);
      } else {
        if (dbResult.length > 0) {
          bcrypt.compare(
            pinkoodi,
            dbResult[0].pinkoodi,
            function (err, compareResult) {
              if (compareResult) {
                console.log("succes");
                response.send(true);
              } else {
                console.log("wrong pinkoodi");
                response.send(false);
              }
            }
          );
        } else {
          console.log("user does not exists");
          response.send(false);
        }
      }
    });
  } else {
    console.log("kortinnumero or pinkoodi missing");
    response.send(false);
  }
});

module.exports = router;
