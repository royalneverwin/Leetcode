class Solution:
    def checkMove(self, board: List[List[str]], rMove: int, cMove: int, color: str) -> bool:
        # up
        if rMove >= 2:
            flag1, flag2 = False, False
            for i in range(rMove-1, -1, -1):
                if board[i][cMove] != '.' and board[i][cMove] != color: # 中间
                    flag1 = True
                    continue
                elif board[i][cMove] == color: # 到了同色
                    if flag1: # 第一次同色中间有异色
                        flag2 = True

                    break

                else: # 结束了
                    break
            
            # 结束了
            if flag2:
                return True

        # down
        if rMove <= 5:
            flag1, flag2 = False, False
            for i in range(rMove+1, 8):
                if board[i][cMove] != '.' and board[i][cMove] != color: # 中间
                    flag1 = True
                    continue
                elif board[i][cMove] == color: # 到了同色
                    if flag1: # 第一次同色中间有异色
                        flag2 = True
                    
                    break

                else: # 结束了
                    break
            
            # 结束了
            if flag2:
                return True

        # left
        if cMove >= 2:
            flag1, flag2 = False, False
            for i in range(cMove-1, -1, -1):
                if board[rMove][i] != '.' and board[rMove][i] != color: # 中间
                    flag1 = True
                    continue
                elif board[rMove][i] == color: # 到了同色
                    if flag1: # 第一次同色中间有异色
                        flag2 = True
                    break

                else: # 结束了
                    break
            
            # 结束了
            if flag2:
                return True

        # right
        if cMove <= 5:
            flag1, flag2 = False, False
            for i in range(cMove+1, 8):
                if board[rMove][i] != '.' and board[rMove][i] != color: # 中间
                    flag1 = True
                    continue
                elif board[rMove][i] == color: # 到了同色
                    if flag1: # 第一次同色中间有异色
                        flag2 = True
                    break

                else: # 结束了
                    break
            
            # 结束了
            if flag2:
                return True

        # upleft
        if rMove >= 2 and cMove >= 2:
            flag1, flag2 = False, False
            for i in range(1, min(rMove, cMove) + 1):
                if board[rMove-i][cMove-i] != '.' and board[rMove-i][cMove-i] != color: # 中间
                    flag1 = True
                    continue
                elif board[rMove-i][cMove-i] == color: # 到了同色
                    if flag1: # 第一次同色中间有异色
                        flag2 = True
                    break

                else: # 结束了
                    break
            
            # 结束了
            if flag2:
                return True

        # upright
        if rMove >= 2 and cMove <= 5:
            flag1, flag2 = False, False
            for i in range(1, min(rMove, 7-cMove) + 1):
                if board[rMove-i][cMove+i] != '.' and board[rMove-i][cMove+i] != color: # 中间
                    flag1 = True
                    continue
                elif board[rMove-i][cMove+i] == color: # 到了同色
                    if flag1: # 第一次同色中间有异色
                        flag2 = True
                    break

                else: # 结束了
                    break
            
            # 结束了
            if flag2:
                return True

        # downleft
        if rMove <= 5 and cMove >= 2:
            flag1, flag2 = False, False
            for i in range(1, min(7-rMove, cMove) + 1):
                if board[rMove+i][cMove-i] != '.' and board[rMove+i][cMove-i] != color: # 中间
                    flag1 = True
                    continue
                elif board[rMove+i][cMove-i] == color: # 到了同色

                    if flag1: # 第一次同色中间有异色
                        flag2 = True
                    break

                else: # 结束了
                    break
            
            # 结束了
            if flag2:
                return True

        # downright
        if rMove <= 5 and cMove <= 5:
            flag1, flag2 = False, False
            for i in range(1, min(7-rMove, 7-cMove) + 1):
                if board[rMove+i][cMove+i] != '.' and board[rMove+i][cMove+i] != color: # 中间
                    flag1 = True
                    continue
                elif board[rMove+i][cMove+i] == color: # 到了同色

                    if flag1: # 第一次同色中间有异色
                        flag2 = True
                    break

                else: # 结束了
                    break
            
            # 结束了
            if flag2:
                return True
    
        return False
