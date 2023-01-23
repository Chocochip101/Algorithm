const discount = [10, 20, 30, 40]
signedUser = -1
sellCost = -1

function calculateEmoticonCost(d, c){
    return (1 - d / 100) * c
}

function backTracking(users, emoticons, emoticonDiscount){

    if (emoticonDiscount.length == emoticons.length){
        totalSigned = 0
        totalCost = 0
        for(let i = 0; i < users.length; i++){
            tempCost = 0
            for(let j = 0; j < emoticons.length; j++){
                if(users[i][0] <= emoticonDiscount[j]){
                    tempCost += calculateEmoticonCost(emoticonDiscount[j], emoticons[j])
                }
            }
            if (tempCost >= users[i][1]){
                totalSigned++
            }else{
                totalCost += tempCost
            }
        }
        if(totalSigned > signedUser){
            signedUser = totalSigned
            sellCost = totalCost
        }else if(totalSigned == signedUser){
            sellCost = Math.max(sellCost, totalCost)
        }
        return
    }

    for (let i = 0; i < discount.length; ++i) {

        emoticonDiscount.push(discount[i])
        backTracking(users, emoticons, emoticonDiscount)
        emoticonDiscount.pop()

      }


}

function solution(users, emoticons) {

    var answer = [];

    backTracking(users, emoticons, [])

    answer.push(signedUser)
    answer.push(sellCost)
    
    return answer;
}
