<template>
  <!-- 体检结果详情 -->
  <div>
    <el-tabs type="border-card">
      <el-tab-pane label="User">
        <el-table :data="tableData" height="250" border style="width: 100%">
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

  <!-- 统计 -->
  <div style="background-color: white;padding: 10px;margin-top: 10px;">
    <el-space class="process" direction="vertical" :fill="100">
      <div>
        <span>统计</span>
        <el-progress :text-inside="true" :stroke-width="20" :percentage="70" />
      </div>
      <div>
        <span>统计</span>
        <el-progress :text-inside="true" :stroke-width="20" :percentage="40" />
      </div>
    </el-space>
  </div>
</template>

<script setup>
// import { ref } from 'vue'

const tableData = [
  {
    id: '1',
    name: 'Tom',
    result: '正常',
    unit: '-',
    reference: '114514',
    prompt: '-',
    abnormal: false,
  },
  {
    id: '2',
    name: 'Tom',
    result: '不正常',
    unit: '-',
    reference: '114514',
    prompt: '-',
    abnormal: true,
  },
  {
    id: '3',
    name: 'Tom',
    result: '正常',
    unit: '-',
    reference: '114514',
    prompt: '-',
    abnormal: false,
  },
  {
    id: '4',
    name: 'Tom',
    result: '正常',
    unit: '-',
    reference: '114514',
    prompt: '-',
    abnormal: false,
  },
  {
    id: '5',
    name: 'Tom',
    result: '正常',
    unit: '-',
    reference: '114514',
    prompt: '-',
    abnormal: false,
  },
  {
    id: '6',
    name: 'Tom',
    result: '不正常',
    unit: '-',
    reference: '114514',
    prompt: '-',
    abnormal: true,
  },
]
</script>

<style lang="scss" scoped>
.process {
  width: 100%;

  // div {
  //   display: flex;
    
  // }
}
</style>
