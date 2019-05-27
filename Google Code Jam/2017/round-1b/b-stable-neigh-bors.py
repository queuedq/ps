def three_colors(N, R, Y, B):
    is_colorable = 2*R <= N and 2*Y <= N and 2*B <= N
    if not is_colorable:
        return None

    arrangement = []

    least, median, most = sorted({'R': R, 'Y': Y, 'B': B}.iteritems(), key=lambda (k,v): (v,k))  # x <= y <= z

    t = median[1] + least[1] - most[1]
    u = median[1]
    v = most[1]

    while v > 0:
        if v > 0:
            arrangement.append(most[0])
            v -= 1
        if u > 0:
            arrangement.append(median[0])
            u -= 1
        else:
            arrangement.append(least[0])
        if t > 0:
            arrangement.append(least[0])
            t -= 1

    return arrangement

T = int(raw_input())

for t in xrange(1, T+1):
    N, R, O, Y, G, B, V = map(int, raw_input().split())

    R_ = R - G
    Y_ = Y - V
    B_ = B - O
    N_ = R_ + Y_ + B_

    result = ''

    if R_ == 0 and Y == 0 and V == 0 and B == 0 and O == 0:
        result = ''.join(['R' if i % 2 == 0 else 'G' for i in xrange(2*R)])
    elif Y_ == 0 and B == 0 and O == 0 and R == 0 and G == 0:
        result = ''.join(['Y' if i % 2 == 0 else 'V' for i in xrange(2*Y)])
    elif B_ == 0 and R == 0 and G == 0 and Y == 0 and V == 0:
        result = ''.join(['B' if i % 2 == 0 else 'O' for i in xrange(2*B)])
    elif (R_ == 0 and R != 0) or (Y_ == 0 and Y != 0) or (B_ == 0 and B != 0):
        result = 'IMPOSSIBLE'
    elif R_ < 0 or Y_ < 0 or B_ < 0:
        result = 'IMPOSSIBLE'
    else:
        arrangement = three_colors(N_, R_, Y_, B_)
        if not arrangement:
            result = 'IMPOSSIBLE'
        else:
            flag_R, flag_Y, flag_B = True, True, True
            for index in xrange(len(arrangement)):
                if arrangement[index] == 'R' and flag_R:
                    arrangement[index] = ''.join(['R' if i % 2 == 0 else 'G' for i in xrange(2*G+1)])
                    flag_R = False
                elif arrangement[index] == 'Y' and flag_Y:
                    arrangement[index] = ''.join(['Y' if i % 2 == 0 else 'V' for i in xrange(2*V+1)])
                    flag_Y = False
                elif arrangement[index] == 'B' and flag_B:
                    arrangement[index] = ''.join(['B' if i % 2 == 0 else 'O' for i in xrange(2*O+1)])
                    flag_B = False

            result = ''.join(arrangement)

#   if result != 'IMPOSSIBLE':
#   
#       color_list = ['R','O','Y','G','B','V']
#       color_count = dict.fromkeys(xrange(6), 0)
#       prev = color_list.index(result[-1])
#       flag = True
#       for i in xrange(len(result)):
#           current = color_list.index(result[i])
#           color_count[current] += 1
#           if (prev - current) % 6 in [0, 1, 5]:
#               flag = False
#               break
#           prev = current
#       comp = [R,O,Y,G,B,V] == color_count.values()
#       print flag, comp

    print 'Case #' + str(t) + ': ' + result
