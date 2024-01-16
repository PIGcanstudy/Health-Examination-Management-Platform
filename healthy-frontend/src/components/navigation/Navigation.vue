<template>

  <div>
      <el-container>
      <el-container class="mater" >
        <el-main >
          <router-link to="/sample/file">
            <img src="../../assets/logo.png" class="ic01"/>
          </router-link>
          <router-link to="/sample/excel">
            <img src="../../assets/logo.png" class="ic02"/>
          </router-link>
          <router-link to="/sample/print">
            <img src="../../assets/logo.png" class="ic03"/>
          </router-link>
          <router-link to="/sample/editor">
            <img src="../../assets/logo.png" class="ic04"/>
          </router-link>
          <router-link to="/sample/pdfobject">
            <img src="../../assets/logo.png" class="ic05"/>
          </router-link>
          <router-link to="/sample/basedatalist">
            <img src="../../assets/logo.png" class="ic06"/>
          </router-link>
          <router-link to="/sample/basedatalisttest">
            <img src="../../assets/logo.png" class="ic07"/>
          </router-link>
          <router-link to="/sample/checkitems">
            <img src="../../assets/logo.png" class="ic08"/>
          </router-link>
          <router-link to="/sample/search">
            <img src="../../assets/logo.png" class="ic09"/>
          </router-link>
          <router-link to="/sample/medicalinfo">
            <img src="../../assets/logo.png" class="ic10"/>
          </router-link>
          <router-link to="/sample/details">
            <img src="../../assets/logo.png" class="ic11"/>
          </router-link>
          <router-link to="/sample/newbutton">
            <img src="../../assets/logo.png" class="ic12"/>
          </router-link>          
        </el-main>
      </el-container>
    </el-container>
  </div>


</template>

<script setup></script>

<style lang="scss" scoped>
// 图标的编号先从左到右，然后从上到下，依次增加
.ic01{
  width: 64px;
  height: 64px;
  left: 80px;
  top: 200px;
}
.ic02{
  width: 64px;
  height: 64px;
  left: 140px;
  top: 200px;
}
.ic03{
  width: 64px;
  height: 64px;
  left: 200px;
  top: 200px;
}
.ic04{
  width: 64px;
  height: 64px;
  left: 260px;
  top: 200px;
}
.ic05{
  width: 64px;
  height: 64px;
  left: 900px;
  top: 200px;
}
.ic06{
  width: 64px;
  height: 64px;
  left: 300px;
  top: 320px;
}
.ic07{
  width: 64px;
  height: 64px;
  left: 360px;
  top: 320px;
}
.ic08{
  width: 64px;
  height: 64px;
  left: 420px;
  top: 320px;
}
.ic09{
  width: 64px;
  height: 64px;
  left: 480px;
  top: 320px;
}
.ic10{
  width: 64px;
  height: 64px;
  left: 580px;
  top: 320px;
}
.ic11{
  width: 64px;
  height: 64px;
  left: -190px;
  top: 450px;
}
.ic12{
  width: 64px;
  height: 64px;
  left: 450px;
  top: 450px;
}
html,
  body,
  .el-container{
    padding: 0;
    margin: 0;
    height: 90vh;
  }
  /* 背景颜色 */
  
</style>