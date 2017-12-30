#Example built from Das Bityard Example with Base 64 encoding <a href="http://bityard.blogspot.com/2010/10/symmetric-encryption-with-pycrypto-part.html" target="_blank" rel="nofollow">http://bityard.blogspot.com/2010/10/symmetric-encryption-with-pycrypto-part.html</a>
#Michael Klopfer, Ph.D.
#University of California, Irvine
#Using Python 2.7.3
#AES-128 Encryption Example
 
from Crypto.Cipher import AES
import base64
 
#Message and Key used in encryption and decryption example
key = '2222222222222222'     #encryption key
plaintext = '0123456789012345'  #message to encrypt
  
#Encrypt and Base-64 encode
encobj = AES.new(key, AES.MODE_ECB)
ciphertext = encobj.encrypt(plaintext)
ciphertext_enc_64 = base64.b64encode(ciphertext)
 
#Decode Base-64 and Decrypt
debase_64_ciphertext = base64.b64decode(ciphertext_enc_64)
decobj = AES.new(key, AES.MODE_ECB)
decrypted_plaintext = decobj.decrypt(debase_64_ciphertext)
  
 
# Test Verification for Encoder
print "*******Inputs********"
print "Message:"
print plaintext
print
print "Key: "
print key
print
print
print "*******Encrypter********"
print "Resulting ciphertext: "
print ciphertext
print "Resulting ciphertext encoded in Base-64: "
print ciphertext_enc_64 
print
print
print "*******Decrypter********"
print "Encoded base 64 ciphertext: "
print ciphertext_enc_64
print "Resulting un-encode Base-64 ciphertext: "
print debase_64_ciphertext 
print "Decrypted Text: "
print decrypted_plaintext