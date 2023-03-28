# This is Python2 only code
print 'Hello'
try:
    print 'World'
    a = 10 / 0
except ValueError, e:
    print 'Error ' + e
