import sys
if sys.prefix == '/usr':
    sys.real_prefix = sys.prefix
    sys.prefix = sys.exec_prefix = '/home/y/SA_CAO_Simu/SA_CAO/install/diablo_simulation'
