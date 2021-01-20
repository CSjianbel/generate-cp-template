import sys
import re

if len(sys.argv) != 2:
    print("Usage: ccpt [outfile.cpp]");
    sys.exit(1)

TEMPLATE_PATH = "./template.cpp"
OUTFILE_PATH = sys.argv[1];

if re.search("\.\w+$", OUTFILE_PATH):
    OUTFILE_PATH = re.sub("\.\w+$", ".cpp", OUTFILE_PATH)
else:
    OUTFILE_PATH += ".cpp"

try:
    with open(OUTFILE_PATH, "w") as outfile:
        with open(TEMPLATE_PATH, "r") as template:
            data = template.read()
            outfile.write(data)
except OSError:
    print("Invalid Filepath")
    sys.exit(3)
    
print(f"Created CP template on {OUTFILE_PATH}")
