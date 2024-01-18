<template>
  <!-- 体检结果详情 -->
  <div>
    <el-tabs type="border-card">
      <el-tab-pane label="User">
        <el-table :data="details" height="250" border style="width: 100%">
          <el-table-column prop="id" label="#" width="60" />
          <el-table-column prop="name" label="体检项目" />
          <el-table-column prop="result" label="明细结果">
            <template #default="{row}">
              <el-input v-model="row.result" placeholder="-" />
            </template>
          </el-table-column>
          <el-table-column prop="unit" label="单位" />
          <el-table-column prop="reference" label="参考值" />
          <el-table-column prop="prompt" label="提示" />
          <el-table-column prop="abnormal" label="异常">
            <template #default="{row}">
              <el-checkbox v-model="row.abnormal" label="是" size="large" />
            </template>
          </el-table-column>
        </el-table>
      </el-tab-pane>
      <el-tab-pane label="Config">Config</el-tab-pane>
      <el-tab-pane label="Role">Role</el-tab-pane>
      <el-tab-pane label="Task">Task</el-tab-pane>
    </el-tabs>
  </div>
</template>

<script setup>
import { defineProps } from 'vue'

const props = defineProps({
  details: {
    type: Array,
    default: () => []
  }
})
</script>

<style lang="scss" scoped></style>
