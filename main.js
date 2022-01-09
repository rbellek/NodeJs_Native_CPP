const { file_checksum } = require(`./native.node`);

console.log(file_checksum("sample.txt")); // crc32 -> 1c291ca3