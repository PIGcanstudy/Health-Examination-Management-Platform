<!-- 用户管理 -->
<template>
   <el-container>
      <el-header style="height: 200px;">
        <div class="dis">
          <div>用户名 <el-input v-model="name" placeholder="请输入用户名" class="model"/></div>

        <div>所属科室  <el-select v-model="value" placeholder="请选择科室" class="model">
    <el-option v-for="item in options" :key="item.value" :label="item.label" :value="item.value"/> </el-select></div>

    <div>手机号<el-input v-model="phone" placeholder="请输入手机号码" class="model"/></div>
    
    <div>邮箱<el-input v-model="mail" placeholder="请输入邮箱" class="model"/></div>
  </div>
    
  <div class="dis">
    <div>性别<el-select v-model="gender" placeholder="选择性别" class="model">
    <el-option v-for="item in options" :key="item.value" :label="item.label" :value="item.value" /></el-select></div>
  
        <div>登录账号<el-input v-model="input" placeholder="请输入登录账号" class="model"/></div>

        <div>用户ID<el-input v-model="input" placeholder="请输入用户ID" class="model"/></div>

        <div>创建时间 <el-input v-model="input" placeholder="输入起始时间" class="model"/></div>
   </div>
        <el-button>搜索</el-button>
        <el-button>重置</el-button>
      </el-header>
      <el-main>
      <el-button>添加用户</el-button>
      <el-button>批量删除</el-button>
      <el-button>更多操作</el-button>
      <el-button>关闭搜索</el-button>
      <el-button>关闭提示</el-button>
        <el-table :data="tableData" height="250" border :cell-style="{ textAlign: 'center' }" :header-cell-style="{ 'text-align': 'center' }" style="width: 100%">
        <el-table-column prop="id" label="" width="60" />
        <el-table-column prop="id" label="#" width="60" />
        <el-table-column prop="name" label="登录账号" />
        <el-table-column prop="result" label="用户名" />
        <el-table-column prop="unit" label="头像" />
        <el-table-column prop="reference" label="所属科室" />
        <el-table-column prop="prompt" label="手机" />
        <el-table-column prop="prompt" label="性别" />
        <el-table-column prop="prompt" label="类型" />
        <el-table-column prop="prompt" label="状态" />
        <el-table-column prop="prompt" label="创建时间" />

      </el-table>
      </el-main>
    </el-container>
</template>

<script setup>
import { ref } from 'vue'
import NewButtonCG from '@/components/details/NewButtonCG.vue'
import { defineProps } from 'vue'
  
  const props = defineProps({
    tableData: {
      type: Array,
      default: () => []
    }
  })
const input = ref('')
const value = ref('')
const name =ref('')
const phone =ref('')
const mail =ref('')
const options = [
  {
    value: 'Option1',
    label: 'Option1',
  }]
  const gender = [
  {
    value: '男',
    label: '男',
  },
  {
    value: '女',
    label: '女',
  }]
</script>

<style lang="scss" scoped>
.model{
  width: 200px;
  line-height: 100px;
  margin: 10px;
}
.dis{
  display: flex;
  justify-content:space-between;
}
</style>
