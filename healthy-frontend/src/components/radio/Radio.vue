<template>
  <el-radio class="radio">
    <div class="main">
      <div class="top">
        <el-row justify="space-between">
          <el-col span="12">
            <div>
              <span>2024-2-3</span>
            </div>
          </el-col>
          <el-col span="12">
            <div class="status">
              <span class="not">未报</span>
              <span class="check">健</span>
            </div>
          </el-col>
        </el-row>
      </div>
      <div class="bottom">
        <el-row justify="space-between">
          <el-col span="12">
            <div>xxx公司</div>
          </el-col>
          <el-col span="12">
            <div class="status">
              <span class="kind">团</span>
            </div>
          </el-col>
        </el-row>
      </div>
    </div>
  </el-radio>
</template>

<style lang="scss" scoped>
.radio {
  justify-content: space-between;
  width: 100%;
  margin-bottom: 10px;
  border-bottom: 1px solid gray;
  height: 100px;
}

.main {
  color: black;
  margin: 10px;
  width: 100%;
}



.top {
  margin: 10px;
  width: 100%;
}

.bottom {
  margin: 10px;
  width: 100%;
}

.not,
.check,
.kind {
  border: 1px solid;
  border-radius: 5px;
  padding: 4px;
  margin-right: 10px;
}

.not {
  color: red;
  border-color: red;
}

.check {
  color: green;
  border-color: green;
}

.kind {
  color: blue;
  border-color: blue;
}
</style>
