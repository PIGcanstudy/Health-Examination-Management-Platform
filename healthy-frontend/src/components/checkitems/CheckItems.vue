<template>
  <el-button type="primary" style="margin-left: 16px" @click="drawer = true">套餐项目</el-button>

  <el-drawer v-model="drawer" title="I am the title" :with-header="false">
    <span>套餐项目</span>
    <div class="demo-input-suffix">
    <!-- <el-row :gutter="20">
      <span class="ml-3 w-35 text-gray-600 inline-flex items-center"
        >关键字: </span
      >
      <el-input
        v-model="input1"
        class="w-50 m-2"
        placeholder="请输入关键字"
        :suffix-icon="Search"
      />
      <span class="ml-3 w-35 text-gray-600 inline-flex items-center"
        >所属科室:</span
      >

    </el-row> -->
  </div>
  </el-drawer>
</template>

<script lang="ts" setup>
import { ref } from 'vue'
const drawer = ref(false)

</script>
<style>
.el-table .warning-row {
  --el-table-tr-bg-color: var(--el-color-warning-light-9);
}
.el-table .success-row {
  --el-table-tr-bg-color: var(--el-color-success-light-9);
}
</style>