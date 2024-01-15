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
    <div id="echars" style="height: 200px;"></div>
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

// 统计
import * as echarts from 'echarts'
import { onMounted } from 'vue'

onMounted(() => {
  var myChart = echarts.init(document.getElementById('echars'))

  myChart.setOption({
    tooltip: {
      trigger: 'item',
      formatter: '{a} <br/>{b}: {c} ({d}%)'
    },
    legend: {
      data: [
        '未评价',
        '已评价',
        '未登记',
        '在体检',
        '已总检',
      ],
      orient: 'vertical',
      left: 'left',
      top: 'top'
    },
    series: [
      {
        name: '体检完成率',
        type: 'pie',
        selectedMode: 'single',
        radius: [0, '55%'],
        label: {
          show: true,
          position: 'inner',
          fontSize: 14
        },
        labelLine: {
          show: false
        },
        data: [
          { value: 1548, name: '未登记' },
          { value: 775, name: '在体检' },
          { value: 679, name: '已总检' }
        ]
      },
      {
        name: '评价完成率',
        type: 'pie',
        radius: ['70%', '90%'],
        labelLine: {
          length: 30
        },
        label: {
          show: true
        },
        data: [
          { value: 1048, name: '已评价' },
          { value: 335, name: '未评价' },
        ]
      }
    ]
  })
})

</script>

<style lang="scss" scoped>

</style>
