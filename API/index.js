var express = require('express')
var bodyParser = require('body-parser')
var app = express()
var router = express.Router()

app.use(bodyParser.json())

app.use(express.static(__dirname + '/public'))
app.use('/scripts', express.static(__dirname + '/node_modules/'));
app.use('/api', router)


var server = app.listen(3000, function(){
  console.log('CultiveBot na porta 3000!')
  console.log('Executando ambiente de desenvolvimento')
})

app.use(bodyParser.urlencoded({ extended: false }));
app.use(bodyParser.json());


module.exports = server;
