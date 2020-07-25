import collections
def find_draw(team_a, team_b):
    draws = 0
    team_a = list(team_a)
    team_b = list(team_b)
    n = len(team_a)
    for i in range(n):
        for j in range(n):
            if team_a[i] == team_b[j]:
                draws += 1
                # team_a[i] = '_'
                team_b[j] = '_'

    return draws
if __name__ == '__main__':
    t = int(input())
    while t > 0:
        n = int(input())
        team_a = str(input())
        team_b = str(input())
        print(find_draw(team_a,team_b))
        t-= 1