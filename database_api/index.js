const http = require('http');

// Core KOA Dependancies
const Koa = require("koa");
const koaJson = require('koa-json');
const koaParser = require('koa-bodyparser');

// Gather routes
const defaultRoute = require('./routes/default');

// Define our constants
const API_PORT = 3000;

// Create a new instance of the KOA API
const api = new Koa();

// Add Middleware
api.use(koaJson());
//api.use(koaParser());


defaultRoute(api);

// Create out server which will listen for calls to the API
http.createServer(api.callback()).listen(API_PORT);