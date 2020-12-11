#!/usr/bin/env node
// to inform the system what type of script is included in the rest of the text file

const axios = require("axios");
const url = "https://quotes.rest/qod/";

axios.get(url, { headers: { Accept: "application/json" } })
 .then(res => {
     var r = res.data.contents.quotes;
    for (i in r) { 
        console.log(r[i].quote);          
    } 
 });