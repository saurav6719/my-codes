const freemem = require('os');

// var freeMemoryInBytes = freemem.freemem();
// var freeMemoryInKiloBytes = freeMemoryInBytes/1024;
// var freeMemoryInMegaBytes = freeMemoryInKiloBytes/1024;
// var freeMemoryInGigaBytes = freeMemoryInMegaBytes/1024;
// console.log(freeMemoryInGigaBytes);
console.log(freemem.homedir());
console.log(freemem.hostname());
console.log(freemem.platform());
console.log(freemem.release());
console.log(freemem.uptime());