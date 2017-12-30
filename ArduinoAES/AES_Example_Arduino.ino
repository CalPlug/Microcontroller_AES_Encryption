//Example AES-128 Encryption for Arduino
//Example built from Das Bityard Example with Base 64 encoding <a href="http://bityard.blogspot.com/2010/10/symmetric-encryption-with-pycrypto-part.html" target="_blank" rel="nofollow">http://bityard.blogspot.com/2010/10/symmetric-encryption-with-pycrypto-part.html</a>
//Michael Klopfer, Ph.D.
//University of California, Irvine
//Tested on Arduino Uno and ESP8266 (Must use a Base64 library without AVR PROGMEM!)
//AES-128 Encryption Example

#include <AESLib.h>  //replace the ( with < to compile (forum posting issue)
#include <Base64.h>
 
//From the examples: <a href="https://github.com/DavyLandman/AESLib" target="_blank" rel="nofollow">https://github.com/DavyLandman/AESLib</a>, <a href="https://github.com/adamvr/arduino-base64" target="_blank" rel="nofollow">https://github.com/adamvr/arduino-base64</a>, <a href="https://github.com/spaniakos/AES" target="_blank" rel="nofollow">https://github.com/spaniakos/AES</a>
 
void setup() {
 
Serial.begin(9600);
uint8_t key[] = {50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50};  //expressed in 16 unsigned in characters, be careful not to typecast this as a char in a decrypter
//16- 50's (uint8) is the way to express 16 2's in ascii, the encryption matches to what will show up on <a href="http://aesencryption.net/" target="_blank" rel="nofollow">http://aesencryption.net/</a>
char data[] = "0123456789012345"; //The message to encrypt, 16 chars == 16 bytes, no padding needed as frame is 16 bytes
 
Serial.print("Message:");
Serial.println(data);
 
 
 
aes128_enc_single(key, data);
 
Serial.print("encrypted:");
 
Serial.println(data);
 
int inputLen = sizeof(data);
int encodedLen = base64_enc_len(inputLen);
char encoded[encodedLen];
base64_encode(encoded, data, inputLen);
 
Serial.print("encrypted(base64):");  //used 
 
Serial.println(encoded);
 
Serial.println("***********Decrypter************");
 
int input2Len = sizeof(encoded);
int decodedLen = base64_dec_len(encoded, input2Len);
char decoded[decodedLen];
   
base64_decode(decoded, encoded, input2Len);
Serial.print("encrypted (returned from Base64):");
Serial.println(decoded);
 
aes128_dec_single(key, decoded);
Serial.print("decrypted:");
Serial.println(decoded);
 
 
}
 
void loop() {
 
}