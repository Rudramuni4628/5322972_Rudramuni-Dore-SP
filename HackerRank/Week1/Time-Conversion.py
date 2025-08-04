def timeConversion(s):
    h=int(s[0:2])
    m=s[3:5]
    s=s[6:8]
    meridian = s[8:]
    
    if meridian == "AM":
        if h ==12:
            h=0
    else:
        if h != 12:
            h += 12
    
    h_24 = f"{h:02d}"
    
    return f"{h_24}:{m}:{s}"
    
