def solution(id_list, report, k):
    answer = []
    reportInfo = {}
    reportLog = set()
    user = {}
    final = set()
    for i in report:
        info = i.split()
        if i in reportLog: continue
        reportLog.add(i)
        if info[1] in reportInfo: reportInfo[info[1]] += 1
        else: reportInfo[info[1]] = 1
        if info[0] in user: user[info[0]].add(info[1])
        else: user[info[0]] = {info[1]}
    
    for i in reportInfo:
        if reportInfo[i]>=k: final.add(i)
    
    for i in id_list:
        cnt = 0
        if i in user:
            for j in user[i]:
                if j in final: cnt += 1
        answer.append(cnt)
        
    return answer
