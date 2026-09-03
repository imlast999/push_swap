import sys

def run_checker():
    raw_args = sys.argv[1:]
    nums = []
    for arg in raw_args:
        for item in arg.split():
            try:
                nums.append(int(item))
            except ValueError:
                print("Error")
                return

    a = list(nums)
    b = []

    lines = sys.stdin.read().splitlines()
    for line in lines:
        line = line.strip()
        if not line:
            continue
        if line == "sa":
            if len(a) >= 2:
                a[0], a[1] = a[1], a[0]
        elif line == "sb":
            if len(b) >= 2:
                b[0], b[1] = b[1], b[0]
        elif line == "ss":
            if len(a) >= 2:
                a[0], a[1] = a[1], a[0]
            if len(b) >= 2:
                b[0], b[1] = b[1], b[0]
        elif line == "pa":
            if len(b) > 0:
                a.insert(0, b.pop(0))
        elif line == "pb":
            if len(a) > 0:
                b.insert(0, a.pop(0))
        elif line == "ra":
            if len(a) > 0:
                a.append(a.pop(0))
        elif line == "rb":
            if len(b) > 0:
                b.append(b.pop(0))
        elif line == "rr":
            if len(a) > 0:
                a.append(a.pop(0))
            if len(b) > 0:
                b.append(b.pop(0))
        elif line == "rra":
            if len(a) > 0:
                a.insert(0, a.pop())
        elif line == "rrb":
            if len(b) > 0:
                b.insert(0, b.pop())
        elif line == "rrr":
            if len(a) > 0:
                a.insert(0, a.pop())
            if len(b) > 0:
                b.insert(0, b.pop())
        else:
            print("Error")
            return

    if len(b) == 0 and a == sorted(a):
        print("OK")
    else:
        print("KO")

if __name__ == "__main__":
    run_checker()
