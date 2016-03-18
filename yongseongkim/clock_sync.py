# -*- coding: utf8 -*-
total_case = input()
case_index = 0
case_count = 0

switches = [
    [0, 1, 2],              # 0 번 스위치
    [3, 7, 9, 11],          # 1 번 스위치
    [4, 10, 14, 15],        # 2 번 스위치
    [0, 4, 5, 6, 7],        # 3 번 스위치
    [6, 7, 8, 10, 12],      # 4 번 스위치
    [0, 2, 14, 15],         # 5 번 스위치
    [3, 14, 15],            # 6 번 스위치
    [4, 5, 7, 14, 15],      # 7 번 스위치
    [1, 2, 3, 4, 5],        # 8 번 스위치
    [3, 4, 5, 9, 13],       # 9 번 스위치
]


def clock_to_12(clocks, clock_idx, switch_idx):
    clock_count = (4 - clocks[clock_idx]) % 4
    for idx in switches[switch_idx]:
        clocks[idx] = (clocks[idx] + clock_count) % 4
    return clock_count


while case_index < total_case:
    case_count = 0
    clocks = [(int(x) / 3) % 4 for x in raw_input().split()]
    # 8번을 움직이는 스위치는 4번 밖에 없다
    # 12번을 움직이는 스위치는 4번 밖에 없다
    # 14번과 15번을 움직이는 스위치는 같다
    if clocks[8] != clocks[12] or clocks[14] != clocks[15]:
        case_count = -1
    else:
        case_count += clock_to_12(clocks, 8, 4)
        # 11번을 움직이는 스위치는 1번 밖에 없다
        case_count += clock_to_12(clocks, 11, 1)
        if clocks[9] != clocks[13]:
            case_count = -1
        else:
            # 13번을 움직이는 스위치는 9번 밖에 없다
            case_count += clock_to_12(clocks, 13, 9)
            # 여기서 6번을 움직이는 스위치는 3번 밖에 없다
            case_count += clock_to_12(clocks, 6, 3)
            # 여기서 10번을 움직이는 스위치는 2번 밖에 없다
            case_count += clock_to_12(clocks, 10, 2)
            # 여기서 7번을 움직이는 스위치는 7번 밖에 없다
            case_count += clock_to_12(clocks, 7, 7)
            # 여기서 5번을 움직이는 스위치는 8번 밖에 없다
            case_count += clock_to_12(clocks, 5, 8)
            if clocks[4] != 0:
                case_count = -1
            else:
                # 여기서 1번을 움직이는 스위치는 0번 밖에 없다
                case_count += clock_to_12(clocks, 1, 0)
                # 여기서 3번을 움직이는 스위치는 6번 밖에 없다
                case_count += clock_to_12(clocks, 3, 6)
                # 여기서 2번을 움직이는 스위치는 5번 밖에 없다
                case_count += clock_to_12(clocks, 2, 5)
                if clocks[0] != 0 or clocks[14] != 0 or clocks[15] != 0:
                    case_count = -1
    print case_count
    case_index += 1
