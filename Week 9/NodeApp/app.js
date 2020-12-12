//>>Set an environment variable NODE_ENV
const dotenv = require('dotenv'); //to find the .env file, parse it, and read them into your Node.js app
dotenv.config();

const port = process.env.PORT;
const node_env = process.env.NODE_ENV;

console.log(`Your port is ${port}`);

//>>Pass a command line argument --stream (with a value true or false)

// const args = require('minimist')(process.argv.slice(2));
// args['stream'];
process.argv.forEach((val, index) => { //The way you retrieve it is using the process object built into Node.js.
//It exposes an argv property, which is an array that contains all the command line invocation arguments.
    if(val=='--stream'){
        var streamValue = process.argv[index+1];
        console.log(streamValue);
    }
    console.log(`${index}: ${val}`)
});


var events = require('events');
var fs = require('fs');
//>>Install moment package as a dependency in your project
var moment = require('moment');

//>>Create an event emitter
var em = new events.EventEmitter();

//>>Add an event listener to listen to the event ‘createFolders’ which should trigger a method to 
//create the following folders if not exists based on the NODE_ENV variable from the environment variables
const folderName = `/Users/swarnika/AddSkill_Projects/NodeApp/${node_env}`;
const subfolderdest = `/Users/swarnika/AddSkill_Projects/NodeApp/${node_env}/dest`;
const subfoldersrc = `/Users/swarnika/AddSkill_Projects/NodeApp/${node_env}/src`;

em.on('createFolders', function () {
    try 
    {
        if (!fs.existsSync(folderName)) {
          fs.mkdirSync(folderName)
            if((!fs.existsSync(subfolderdest)) || (!fs.existsSync(subfoldersrc))){
                fs.mkdirSync(subfolderdest);
                fs.mkdirSync(subfoldersrc);
            }
        }
    } catch (err) {
        console.error(err)
    }
});

em.emit('createFolders');

//>>Add an event listener to listen to the event ‘createSourceFile’ which should trigger a method to create a file 
//in the src folder with the filename as YYYY_MM_DD_HH_MM_SS.txt (Use moment package to generate the filename) 
//and add some random text to it.
const fileName = moment().format();
const filePath = `/Users/swarnika/AddSkill_Projects/NodeApp/${node_env}/src/${fileName}.txt`;

em.on('createSourceFile', function () {
    fs.writeFile(filePath, 'Learn Node FS module', function (err) {
        if (err) throw err;
        console.log('File is created successfully.');
      }); 
});

em.emit('createSourceFile');


// var http = require('http');

// //create a server object:
// http.createServer(function (req, res) {
//   res.write('Hello World!'); //write a response to the client
//   res.end(); //end the response
// }).listen(8080); //the server object listens on port 8080

const file = fs.createWriteStream(filePath); //writing to a file using writable stream

for(let i=0; i<= 2; i++) {
  file.write('Lorem ipsum dolor sit amet, consectetur adipisicing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum.\n');
}

file.end();

const server = require('http').createServer();

server.on('request', (req, res) => {
  fs.readFile(filePath, (err, data) => { //fs.readfile is asynchronous method
    if (err) throw err;
    res.end(data);
  });
});

// server.on('request', (req, res) => {
//     const src = fs.createReadStream('./big.file');
//     src.pipe(res);
//   });

server.listen(8000);