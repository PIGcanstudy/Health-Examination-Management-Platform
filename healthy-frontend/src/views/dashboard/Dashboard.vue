<template>
   <div class="btn01">
    <el-button @click="enter01" style="position: fixed;width: 130px;height: 50px;font-size: larger;font-weight: 200;">点击进入</el-button>
   </div>
   <div class="icon01">
      <img src="../../assets/dashboard/icon01.png" style="height: 195px;width: 350px;">
   </div>

   <div class="btn02">
    <el-button style="position: fixed;width: 130px;height: 50px;font-size: larger;font-weight: 200;">点击进入</el-button>
   </div>
   <div class="icon02">
      <img src="../../assets/dashboard/icon02.png" style="height: 195px;width: 350px;">
   </div>

   <div class="btn03">
    <el-button style="position: fixed;width: 130px;height: 50px;font-size: larger;font-weight: 200;">点击进入</el-button>
   </div>
   <div class="icon03">
      <img src="../../assets/dashboard/icon03.png" style="height: 400px;width: 434px;">
   </div>

   <div class="btn04">
    <el-button style="position: fixed;width: 130px;height: 50px;font-size: larger;font-weight: 200;">点击进入</el-button>
   </div>
   <div class="icon04">
      <img src="../../assets/dashboard/icon04.png" style="height: 400px;width: 230px;">
   </div>
   
   <div class="btn05">
    <el-button style="position: fixed;width: 130px;height: 50px;font-size: larger;font-weight: 200;">点击进入</el-button>
   </div>
   <div class="icon05">
      <img src="../../assets/dashboard/icon05.png" style="height: 195px;width: 350px;">
   </div>

   <div class="btn06">
    <el-button style="position: fixed;width: 130px;height: 50px;font-size: larger;font-weight: 200;">点击进入</el-button>
   </div>
   <div class="icon06">
      <img src="../../assets/dashboard/icon06.png" style="height: 195px;width: 350px;">
   </div>
</template>

<script setup>
  import{RouterView,RouterLink,useRouter} from 'vue-router'

  const router = useRouter()

  function enter01(){
    router.push('/un-1')
  }

</script>

<style lang="css" scoped>
.icon01{
  
  position: absolute;
  left: 50px;
  top: 200px;
}
.btn01{
  left: 250px;
  top: 295px;
  z-index: 9999;
  position: absolute;
}

.icon02{
  
  position: absolute;
  left: 50px;
  top: 405px;
}
.btn02{
  left: 250px;
  top: 505px;
  z-index: 9999;
  position: absolute;
}


.icon03{
  
  position: absolute;
  left: 410px;
  top: 200px;
}
.btn03{
  left: 420px;
  top: 400px;
  z-index: 9999;
  position: absolute;
}

.icon04{
  
  position: absolute;
  left: 850px;
  top: 200px;
}
.btn04{
  left: 900px;
  top: 270px;
  z-index: 9999;
  position: absolute;
}
.icon05{
  
  position: absolute;
  left: 1085px;
  top: 200px;
}
.btn05{
  left: 1290px;
  top: 295px;
  z-index: 9999;
  position: absolute;
}

.icon06{
  
  position: absolute;
  left: 1085px;
  top: 405px;
}
.btn06{
  left: 1290px;
  top: 500px;
  z-index: 9999;
  position: absolute;
}
</style>
