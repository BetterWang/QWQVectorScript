import math, cmath

particle_p = [ 0, 3.1, 0.1 ]
particle_n = [ 0, 0.1, 3.1, -3.1 ]

s2p1_1 = 0.;
s2p2_2 = 0.;
s2p1p1 = 0.;
s2p1_2 = 0.;

w2p1_1 = 0.;
w2p2_2 = 0.;
w2p1p1 = 0.;
w2p1_2 = 0.;


part_all = [[1, i] for i in particle_p] + [ [-1, i] for i in particle_n]

spn11_2 = 0;
wpn11_2 = 0;
#+-a
for idx1, part1 in enumerate(part_all):
    if part1[0] != 1:
        continue
    for idx2, part2 in enumerate(part_all):
        if part2[0] != -1 or idx2 == idx1:
            continue
        for idx3, part3 in enumerate(part_all):
            if idx3 == idx2 or idx3 == idx1:
                continue
            spn11_2 += math.cos(part1[1] + part2[1] - 2*part3[1]);
            wpn11_2 += 1;

print "spn11_2 = ", spn11_2
print "wpn11_2 = ", wpn11_2


snp11_2 = 0;
wnp11_2 = 0;
#-+a
for idx1, part1 in enumerate(part_all):
    if part1[0] != -1:
        continue
    for idx2, part2 in enumerate(part_all):
        if part2[0] != 1 or idx2 == idx1:
            continue
        for idx3, part3 in enumerate(part_all):
            if idx3 == idx2 or idx3 == idx1:
                continue
            snp11_2 += math.cos(part1[1] + part2[1] - 2*part3[1]);
            wnp11_2 += 1;

print "snp11_2 = ", snp11_2
print "wnp11_2 = ", wnp11_2

spp11_2 = 0;
wpp11_2 = 0;

for idx1, part1 in enumerate(part_all):
    if part1[0] != 1:
        continue
    for idx2, part2 in enumerate(part_all):
        if part2[0] != 1 or idx2 == idx1:
            continue
        for idx3, part3 in enumerate(part_all):
            if idx3 == idx2 or idx3 == idx1:
                continue
            spp11_2 += math.cos(part1[1] + part2[1] - 2*part3[1]);
            wpp11_2 += 1;

print "spp11_2 = ", spp11_2
print "wpp11_2 = ", wpp11_2

snn11_2 = 0;
wnn11_2 = 0;

for idx1, part1 in enumerate(part_all):
    if part1[0] != -1:
        continue
    for idx2, part2 in enumerate(part_all):
        if part2[0] != -1 or idx2 == idx1:
            continue
        for idx3, part3 in enumerate(part_all):
            if idx3 == idx2 or idx3 == idx1:
                continue
            snn11_2 += math.cos(part1[1] + part2[1] - 2*part3[1]);
            wnn11_2 += 1;

print "snn11_2 = ", snn11_2
print "wnn11_2 = ", wnn11_2



s = 0
w = 0

for idx1, part1 in enumerate(part_all):
    if part1[0] != 1:
        continue
    for idx2, part2 in enumerate(part_all):
        if part2[0] != -1 or idx2 == idx1:
            continue
        s += math.cos(2*part1[1] - 2*part2[1])
        w += 1

print "spn2_2 = ", s
print "wpn2_2 = ", w

s = 0
w = 0
for idx1, part1 in enumerate(part_all):
    if part1[0] != 1:
        continue
    for idx2, part2 in enumerate(part_all):
        if part2[0] != 1 or idx2 == idx1:
            continue
        s += math.cos(2*part1[1] - 2*part2[1])
        w += 1

print "spp2_2 = ", s
print "wpp2_2 = ", w

s = 0
w = 0
for idx1, part1 in enumerate(part_all):
    if part1[0] != -1:
        continue
    for idx2, part2 in enumerate(part_all):
        if part2[0] != -1 or idx2 == idx1:
            continue
        s += math.cos(2*part1[1] - 2*part2[1])
        w += 1

print "snn2_2 = ", s
print "wnn2_2 = ", w

s = 0
w = 0
for idx1, part1 in enumerate(part_all):
    if part1[0] != -1:
        continue
    for idx2, part2 in enumerate(part_all):
        if part2[0] != -1 or idx2 == idx1:
            continue
        s += math.cos(part1[1] - part2[1])
        w += 1

print "snn1_1 = ", s
print "wnn1_1 = ", w

s = 0
w = 0
for idx1, part1 in enumerate(part_all):
    if part1[0] != 1:
        continue
    for idx2, part2 in enumerate(part_all):
        if part2[0] != 1 or idx2 == idx1:
            continue
        s += math.cos(part1[1] - part2[1])
        w += 1

print "spp1_1 = ", s
print "wpp1_1 = ", w


s = 0
w = 0
for idx1, part1 in enumerate(part_all):
    s += complex(math.cos(2*part1[1]), math.sin(2*part1[1]) )
    w += 1

print "s2_2 = ", s
print "w2_2 = ", w

s = 0
w = 0
for idx1, part1 in enumerate(part_all):
    if part1[0] != 1:
        continue
    for idx2, part2 in enumerate(part_all):
        if part2[0] != -1 or idx2 == idx1:
            continue
        s += math.cos(part1[1] - part2[1])
        w += 1

print "spn1_1 = ", s
print "wpn1_1 = ", w

s = 0
w = 0
for idx1, part1 in enumerate(part_all):
    for idx2, part2 in enumerate(part_all):
        if idx1 == idx2:
            continue
        #s += part1[0]*part2[0]*math.cos(part1[1] - part2[1])
        s += part1[0]*part2[0]*math.cos(part1[1] - part2[1])
        w += 1

print "S1c = ", s
print "W1c = ", w

s = 0
w = 0
for idx1, part1 in enumerate(part_all):
    for idx2, part2 in enumerate(part_all):
        if idx1 == idx2:
            continue
        #s += part1[0]*part2[0]*math.cos(part1[1] - part2[1])
        s += math.cos(2*part1[1] - 2*part2[1])
        w += 1

print "S2 = ", s
print "W2 = ", w

s = 0
w = 0
for idx1, part1 in enumerate(part_all):
    for idx2, part2 in enumerate(part_all):
        if idx1 == idx2:
            continue
        for idx3, part3 in enumerate(part_all):
            if idx3 == idx2 or idx3 == idx1:
                continue
            s += part1[0]*part2[0]*math.cos(part1[1] + part2[1] - 2 * part3[1])
            w += 1

print "S3c = ", s
print "W3c = ", w


'''
Complex Q1p  = Complex(0.995869,0.141414)
Complex Q1p2 = Complex(-1.98825,0)
Complex Q2p1 = Complex(2.97661,0.11558)
Complex Q2p2 = Complex(5.87356,0)
Complex Q3p2 = Complex(-2.00485,0.16608)
Complex Q3p3 = Complex(-1.97197,0.726075)
Complex QMp2 = Complex(1.98479,0.447246)
double wp1  = 3
double wp2  = 6
double wp3  = 6
Complex Q1n  = Complex(-0.00326614,0.0998334)
Complex Q1n2 = Complex(-3.99002,0)
Complex Q2n1 = Complex(3.97315,0.198669)
Complex Q2n2 = Complex(11.8254,0)
Complex Q3n2 = Complex(-3.98311,-0.199321)
Complex Q3n3 = Complex(-7.88504,-0.000613086)
Complex QMn2 = Complex(0.0101231,0.497136)
double wn1  = 4
double wn2  = 12
double wn3  = 24
'''
