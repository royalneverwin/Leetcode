from collections import defaultdict

class Solution:
    def __init__(self, adj_table, visited_dict):
        self.adj_table = adj_table
        self.visited_dict = visited_dict

    def dfs(self, cur_node):
        self.visited_dict[cur_node] = 1
        for nxt_node in self.adj_table[cur_node]:
            if not self.visited_dict[nxt_node]:
                if not self.dfs(nxt_node):
                    return False
            else:
                return False
            
        return True


def main():
    case_cnt = 1
    visited_dict = {}
    adj_table = defaultdict(list)
    is_root_dict = {}  # 如果被指向，则一定不是root
    total_flag = True
    while total_flag:
        line = input()
        # The input will consist of a sequence of descriptions (test cases) followed by a pair of negative integers.
        if line != '':
            edges = list(map(int, line.split()))
            for i in range(0, len(edges), 2):
                if edges[i] == 0 and edges[i+1] == 0:
                    if len(visited_dict.keys()) == 0: # empty tree
                        print(f'Case {case_cnt} is a tree.')
                        # 重置
                        case_cnt += 1
                        visited_dict = {}
                        adj_table = defaultdict(list)
                        is_root_dict = {}  # 如果被指向，则一定不是root
                        continue

                    # find root
                    root_flag = 0
                    root_node = None
                    for key, val in is_root_dict.items():
                        if val:
                            root_flag += 1
                            root_node = key
                    
                    if root_flag == 0:  # 如果没有root，一定不是tree
                        print(f'Case {case_cnt} is not a tree.')
                        # 重置
                        case_cnt += 1
                        visited_dict = {}
                        adj_table = defaultdict(list)
                        is_root_dict = {}  # 如果被指向，则一定不是root
                        continue

                    if root_flag > 1: #如果root大于一个 也一定不是tree
                        print(f'Case {case_cnt} is not a tree.')
                        # 重置
                        case_cnt += 1
                        visited_dict = {}
                        adj_table = defaultdict(list)
                        is_root_dict = {}  # 如果被指向，则一定不是root
                        continue

                    sol = Solution(adj_table, visited_dict)

                    flag = sol.dfs(root_node)
                    # 从root开始bfs，每个结点都应该被访问到(!=0)，每个结点不能被访问到多次(!=2)
                    if 0 not in visited_dict.values() and flag:
                        print(f'Case {case_cnt} is a tree.')
                    else:
                        print(f'Case {case_cnt} is not a tree.')
                    # 重置
                    case_cnt += 1
                    visited_dict = {}
                    adj_table = defaultdict(list)
                    is_root_dict = {}  # 如果被指向，则一定不是root
                        
                    
                elif edges[i] < 0 or edges[i+1] < 0:
                    total_flag = False
                    break
                
                else:
                    visited_dict[edges[i]] = 0
                    visited_dict[edges[i+1]] = 0
                    adj_table[edges[i]].append(edges[i+1])
                    if edges[i] not in is_root_dict:
                        is_root_dict[edges[i]] = True
                    is_root_dict[edges[i+1]] = False
                    
        else:
            continue

    return


if __name__ == '__main__':
    main()
