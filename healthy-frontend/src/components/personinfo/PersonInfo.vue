
<template>
  <!-- 人员信息 -->
  <div>
    <el-tabs type="border-card">
      <el-tab-pane label="男">
        <el-table :data="personInfo" border style="width: 100%; margin-top: 10px">
          <el-table-column prop="id" label="体检编号" />
          <el-table-column prop="name" label="姓名" />
          <el-table-column prop="result" label="性别" />
          <el-table-column prop="reference" label="证件号码" />
          <el-table-column prop="unit" label="年龄" />
          <el-table-column prop="prompt" label="操作" />
        </el-table>
      </el-tab-pane>
      <el-tab-pane label="女">
        <el-table :data="personInfo" border style="width: 100%; margin-top: 10px">
          <el-table-column prop="id" label="体检编号" />
          <el-table-column prop="name" label="姓名" />
          <el-table-column prop="result" label="性别" />
          <el-table-column prop="reference" label="证件号码" />
          <el-table-column prop="unit" label="年龄" />
          <el-table-column prop="prompt" label="操作" />
        </el-table>
      </el-tab-pane>
    </el-tabs>
  </div>
</template>

<script setup>
import { defineProps } from 'vue'
import { ref } from 'vue'

// 分页相关
const currentPage = ref(1)
const pageSize = ref(10)

const props = defineProps({
  personInfo: {
    type: Array,
    default: () => []
  }
})
</script>

<style lang="scss" scoped></style>
