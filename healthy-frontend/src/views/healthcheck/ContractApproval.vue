<!-- 合同审批 -->
<template>
  <el-container>
    <el-header class="header">
      <a class="header-text">首页</a>
      <a class="header-text">健康体检</a>
      <a class="header-text">团单审批</a>

    </el-header>
  <el-container>
  <el-aside width="200px">
      </el-aside>
      <el-main>
        <div display:flex size="large">
          <el-button size="default">合同二级审核</el-button>
          <el-button size="default">评审报告预览</el-button>
          <el-button size="default">委托协议预览</el-button>
        </div>
        <!-- 体检项目 -->
        <div width="700px">
          <div><el-text>体检项目</el-text></div>
          <PersonInfo :personInfo="tableData" style="margin-bottom: 15px" />
          <div><el-text>体检人员</el-text></div>
          <div><el-text class="main-body-right">基本信息</el-text></div>
          <PersonInfo :personInfo="tableData" style="margin-bottom: 15px" />
          <div display:flex class="line-text">共0条
            <el-select
    v-model="value"
    class="m-2"
    placeholder="Select"
    size="large"
    style="width: 140px"
  >
    <el-option
      v-for="item in options"
      :key="item.value"
      :label="item.label"
      :value="item.value"
    />
  </el-select>
  跳至
      <el-input-number v-model="num" :min="1" :max="10" @change="handleChange" />
      页
          </div>
          <h3>订单合计:  sum ￥元</h3>
        </div>
          <el-card class="main-body-right">
            <template #header>
            <div>基本信息</div>
            </template>
            <div>合同名称:</div>
            <div>合同编号:</div>
            <div>委托单位:</div>
            <div>委托内容:</div>
            <div>编制部门:</div>
            <div>编制人:</div>
            <div>审核人:</div>
            <div>审核状态:</div>
            <div>联系人:</div>
            <div>联系电话:</div>
            <div>审核日期:</div>
            <div>销售负责人:</div>
            <div>签订时间:</div>
            <div>交付时间:</div>
          </el-card>
      </el-main>
    </el-container>
      </el-container>
</template>

<script setup>
import { ref } from 'vue';
const value = ref('')
const options = [
  {
    value: '10条/页',
    label: '10条/页',
  },
  {
    value: '20条/页',
    label: '20条/页',
  },
  {
    value: '30条/页',
    label: '30条/页',
  },
]
const num = ref(1);
const handleChange = (value) => {
  console.log(value);
};
</script>

<style lang="scss" scoped>

</style>
<style>
.header{
  background-color: blue;
  text-align: center;
  font-size: large;
  height: 50px;
}
.header-text{
  line-height: 25px;
}
.main-body-right{
  margin-right: 2px;
  width: 200px;
}
.header-text{
  margin: 30px;
}
.line-text{
  text-align: right;
}
</style>
